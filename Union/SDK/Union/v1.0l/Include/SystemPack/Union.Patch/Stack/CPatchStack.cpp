#include <UnionAfx.h>

namespace SystemPack
{
	CPatchStack::CPatchStack()
	{
		pPrev	= Null;
		pNext	= Null;
		pObject	= Null;
	}

	CPatchStack* CPatchStack::CreateStack(const CString& line)
	{
		ASSERT( !line.IsEmpty(), "Невозможно создать стек из пустой строки" );

		CPatchStack* stack = new CPatchStack;
		CPatchStack* rtn = stack;

		uint32 ulLastIndex = 0;
		for (uint32 i = 1;; i++)
		{
			CString sWord = line.GetSymbolEx( arrResource, ulResourceNum, arrBrackets, 4, 1, &ulLastIndex );
			ulLastIndex += sWord.Length();

			if( sWord.IsEmpty() )
			{
				break;
			}
			CPatchStack*  next	  = new CPatchStack;
			CPatchSymbol* pSymbol = CPatchSymbol::CreateSymbol( sWord );

			CPatchFunction* pFunc = dynamic_cast<CPatchFunction*>( pSymbol );
			if( pFunc )
			{
				CString sArguments = line.GetSymbolEx( arrResource, ulResourceNum, arrBrackets, 4, 1, &ulLastIndex );
				ulLastIndex += sArguments.Length();

				pFunc->CreateParameters( sArguments );
			}

			next->SetData( pSymbol );
			stack->PushNext( next );
			stack = next;
		}
		return rtn;
	}

#pragma region Helpers

#define MATCH(idx)																		\
	pOperator->sOperator == sOperators[idx]

#define DO_STACK(cond)																	\
	{																					\
		CPatchStack* stack = Next();													\
		while (stack)																	\
		{																				\
			CPatchOperator* pOperator = dynamic_cast<CPatchOperator*>(stack->pObject);	\
			if( pOperator )																\
			{																			\
				if( cond )																\
					pOperator->Execute();												\
			}																			\
			stack = stack->Next();														\
		}																				\
	}

#pragma endregion Helpers


	CPatchSymbol* CPatchStack::Execute()
	{
		//
		//	Создание ссылок
		//
		DO_STACK( MATCH(18) );



		//
		//	Вычисление функций
		//
		{
			CPatchStack* stack = Next();
			while (stack)
			{
				CPatchFunction* pFunction = dynamic_cast<CPatchFunction*>(stack->pObject);
				if( pFunction )
				{
					CPatchSymbol* pSymbol = pFunction->Execute();
					pFunction->Release();
					stack->pObject = pSymbol;
				}
				stack = stack->Next();
			}
		}

		//
		//	Преобразование типов
		//
		{
			CPatchStack* stack = Next();
			while (stack)
			{
				CPatchOperator* pOperator = dynamic_cast<CPatchOperator*>(stack->pObject);
				if( pOperator )
				{
					if( TSymBuilder::GetBySynonym( pOperator->sOperator ))
					{
						pOperator->Execute();
					}
				}
				stack = stack->Next();
			}
		}

		//
		//	Математические и логиечские операторы
		//
		
		DO_STACK( MATCH(3)  || MATCH(4)  || MATCH(5)  || MATCH(8)  || MATCH(9)  || MATCH(10)			  );
		DO_STACK( MATCH(1)  || MATCH(2)  || MATCH(6)  || MATCH(7)										  );
		DO_STACK( MATCH(0)																				  );
		DO_STACK( MATCH(11) || MATCH(12) || MATCH(13) || MATCH(14) || MATCH(15) || MATCH(16) || MATCH(17) );
		DO_STACK( MATCH(19) || MATCH(20)																  );

		//CPatchType* pSymbol = dynamic_cast<CPatchType*>( Next()->pObject );
		if( Num() > 1 )
		{
			//Say::Box( ">> " + A Num() );
			ASSERT_PATCH_ERROR( "Ожидается оператор" );
		}
		return Next()->pObject;
	}

#undef MATCH
#undef DO_STACK

	void CPatchStack::PushNext(CPatchStack* stack)
	{
		ASSERT( !stack->pNext && !stack->pPrev, "Попытка вставить элемент одного стека в другой" );
		if( pNext )
			pNext->pPrev = stack;
		stack->pNext = pNext;
		stack->pPrev = this;
		pNext = stack;
	}

	void CPatchStack::PushBack(CPatchStack* stack)
	{
		ASSERT( !stack->pNext && !stack->pPrev, "Попытка вставить элемент одного стека в другой" );
		if (pPrev)
			pPrev->pNext = stack;
		stack->pPrev = pPrev;
		stack->pNext = this;
		pPrev = stack;
	}

	void CPatchStack::Destroy()
	{
		if (pNext) pNext->Destroy();
		delete this;
	}

	CPatchStack* CPatchStack::Prev ()
	{
		return pPrev;
	}

	CPatchStack* CPatchStack::Next ()
	{
		return pNext;
	}

	uint32 CPatchStack::Num ()
	{
		CPatchStack* stack = pNext;
		uint32 num = 0;
		while (stack)
		{
			num++;
			stack = stack->pNext;
		}
		return num;
	}

	CPatchSymbol* CPatchStack::GetData()
	{
		return pObject;
	}

	void CPatchStack::SetData(CPatchSymbol* object)
	{
		/*if( pObject )
			pObject->Release();*/
		pObject = object;
		//pObject->AddRef();

		CPatchOperator* pOperator = dynamic_cast<CPatchOperator*>( object );
		if( pOperator )
			pOperator->pOnStack = this;
	}

	CPatchStack::~CPatchStack()
	{
		if( pObject )
		{
			//Say::Question(1);
			CPatchOperator* pOperator = dynamic_cast<CPatchOperator*>( pObject );
			if( pOperator )
			{
				//Say::Question(2);
				pOperator->pOnStack = Null;
			}
			pObject->Release();
		}
		if (pPrev) pPrev->pNext = pNext;
		if (pNext) pNext->pPrev = pPrev;
	}
}