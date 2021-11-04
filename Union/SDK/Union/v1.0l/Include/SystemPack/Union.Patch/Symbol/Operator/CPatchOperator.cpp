#include <UnionAfx.h>

namespace SystemPack
{
	PATCH_CLASS_DEFINITION(CPatchOperator, "Operator");

	CPatchOperator::CPatchOperator()
	{
		
	}

	void CPatchOperator::Init(const CString& opName)
	{
		sOperator = opName;
	}

	CPatchType*	CPatchOperator::Execute()
	{
		CPatchStack* stack	  = pOnStack;
		TSymBuilder* pBuilder = TSymBuilder::GetBySynonym( sOperator );
		if( pBuilder )
		{
			ASSERT_PATCH( stack->Next(), "��������� ������ �������\n" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( pBuilder->CreateSymbol() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );
			if( pType1 && pType2 )
			{
				pType1->Init();
				(*pType1) = pType2;
				Release();
				stack->SetData( pType1 );
				delete stack->Next();
				return pType1;
			}
			else
				ASSERT_PATCH_ERROR( "����������� �������� ������ �� ����" );
		}

		uint32 idx = 0;
		// =
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '='" );

			(*pType1) = pType2;
			pType1->AddRef();

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType1);
			Release();

			pType1->WriteOption();
			return pType1;
		}
		// +
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '+'" );

			CPatchType* pType3 = (*pType1) + pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// -
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '-'" );

			CPatchType* pType3 = (*pType1) - pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// *
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '*'" );

			CPatchType* pType3 = (*pType1) * pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// /
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '/'" );

			CPatchType* pType3 = (*pType1) / pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// ^
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '^'" );

			CPatchType* pType3 = (*pType1) ^ pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// +=
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '+='" );

			CPatchType* pType3 = (*pType1) += pType2;
			pType3->AddRef();

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			pType1->WriteOption();
			return pType3;
		}
		// -=
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '-='" );

			CPatchType* pType3 = (*pType1) -= pType2;
			pType3->AddRef();

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			pType1->WriteOption();
			return pType3;
		}
		// *=
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '*='" );

			CPatchType* pType3 = (*pType1) *= pType2;
			pType3->AddRef();

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			pType1->WriteOption();
			return pType3;
		}
		// /=
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '/='" );

			CPatchType* pType3 = (*pType1) /= pType2;
			pType3->AddRef();

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			pType1->WriteOption();
			return pType3;
		}
		// ^=
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '^='" );

			CPatchType* pType3 = (*pType1) ^= pType2;
			pType3->AddRef();

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			pType1->WriteOption();
			return pType3;
		}
		// !
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 )
				ASSERT_PATCH_ERROR( "��������� ��������� ������ �� '!'" );

			CPatchType* pType2 = !(*pType1);

			delete stack->Next();
			stack->SetData(pType2);
			Release();

			return pType2;
		}
		// ==
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '=='" );

			CPatchType* pType3 = (*pType1) == pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// !=
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '!='" );

			CPatchType* pType3 = (*pType1) != pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// <
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '<'" );

			CPatchType* pType3 = (*pType1) < pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// <=
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '<='" );

			CPatchType* pType3 = (*pType1) <= pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// >
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '>'" );

			CPatchType* pType3 = (*pType1) > pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// >=
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pType1 = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pType2 = dynamic_cast<CPatchType*>( stack->Next()->GetData()->Execute() );

			if( !pType1 || !pType2 )
				ASSERT_PATCH_ERROR( "��������� ��������� ����� � ������ �� '>='" );

			CPatchType* pType3 = (*pType1) >= pType2;

			delete stack->Prev();
			delete stack->Next();
			stack->SetData(pType3);
			Release();

			return pType3;
		}
		// @
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchOperator* pOperator = dynamic_cast<CPatchOperator*>( stack->Prev()->GetData() );
			CPatchOperator* pOption   = dynamic_cast<CPatchOperator*>( stack->Next()->GetData() );
			ASSERT_PATCH( pOperator, "��������� ��� ������" );

			TSymBuilder* pBuilder = TSymBuilder::GetBySynonym( pOperator->sOperator );
			ASSERT_PATCH( pBuilder, "�� ������ ������� � '" + pOperator->sOperator + "'" );

			CPatchType* pSymbol = dynamic_cast<CPatchType*>( pBuilder->CreateSymbol() );
			ASSERT_PATCH( pSymbol, "'" + pOperator->sOperator + "' �� ������������ ���" );

			if( pOption && pOption->sOperator.HasWord(":") > 0 )
			{
				pSymbol->Init();
				pSymbol->SetOption( pOption->sOperator );
				pSymbol->ReadOption();
			}
			else
			{
				CPatchInteger*  pInteger  = dynamic_cast<CPatchInteger*> ( stack->Next()->GetData()->Execute() );
				ASSERT_PATCH( pInteger,  "����������� ������ ������ ���� �������������" );

				pSymbol->Init( pInteger->GetValue() );
			}
			delete stack->Prev();
			delete stack->Next();
			Release();
			stack->SetData( pSymbol );

			return pSymbol;
#if 0
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchOperator* pOperator = dynamic_cast<CPatchOperator*>( stack->Prev()->GetData() );
			CPatchInteger*  pInteger  = dynamic_cast<CPatchInteger*> ( stack->Next()->GetData()->Execute() );

			ASSERT_PATCH( pOperator, "��������� ��� ������" );
			ASSERT_PATCH( pInteger,  "����������� ������ ������ ���� �������������" );

			TSymBuilder* pBuilder = TSymBuilder::GetBySynonym( pOperator->sOperator );
			ASSERT_PATCH( pBuilder, "�� ������ ������� � '" + pOperator->sOperator + "'" );

			CPatchType* pSymbol = dynamic_cast<CPatchType*>( pBuilder->CreateSymbol() );
			ASSERT_PATCH( pSymbol, "'" + pOperator->sOperator + "' �� ������������ ���" );

			pSymbol->Init( pInteger->GetValue() );

			delete stack->Prev();
			delete stack->Next();
			Release();
			stack->SetData( pSymbol );

			return pSymbol;
#endif
		}
		// &&
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pLeft  = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pRight = dynamic_cast<CPatchType*>( stack->Next()->GetData() );

			ASSERT_PATCH( pLeft,  "��������� ����� �������" );
			ASSERT_PATCH( pRight, "��������� ������ �������" );

			CPatchBool* pLeftBool = new CPatchBool;
			pLeftBool->Init();
			(*pLeftBool) = pLeft;
			bool32 bLeft = pLeftBool->GetValue();
			delete pLeftBool;

			CPatchBool* pRightBool = new CPatchBool;
			pRightBool->Init();
			(*pRightBool) = pRight;
			bool32 bRight = pRightBool->GetValue();
			delete pRightBool;

			CPatchBool* pBool = new CPatchBool;
			pBool->Init();
			pBool->SetValue( bLeft && bRight );

			delete stack->Prev();
			delete stack->Next();
			Release();
			stack->SetData( pBool );

			return pBool;
		}
		// ||
		if( sOperator == sOperators[idx++] )
		{
			ASSERT_PATCH( stack->Prev(), "��������� ����� �������" );
			ASSERT_PATCH( stack->Next(), "��������� ������ �������" );

			CPatchType* pLeft  = dynamic_cast<CPatchType*>( stack->Prev()->GetData() );
			CPatchType* pRight = dynamic_cast<CPatchType*>( stack->Next()->GetData() );

			ASSERT_PATCH( pLeft,  "��������� ����� �������" );
			ASSERT_PATCH( pRight, "��������� ������ �������" );

			CPatchBool* pLeftBool = new CPatchBool;
			pLeftBool->Init();
			(*pLeftBool) = pLeft;
			bool32 bLeft = pLeftBool->GetValue();
			delete pLeftBool;

			CPatchBool* pRightBool = new CPatchBool;
			pRightBool->Init();
			(*pRightBool) = pRight;
			bool32 bRight = pRightBool->GetValue();
			delete pRightBool;

			CPatchBool* pBool = new CPatchBool;
			pBool->Init();
			pBool->SetValue( bLeft || bRight );

			delete stack->Prev();
			delete stack->Next();
			Release();
			stack->SetData( pBool );

			return pBool;
		}
		return Null;
	}

	CString CPatchOperator::GetOperator()
	{
		return sOperator;
	}

	CPatchOperator::~CPatchOperator()
	{
		
	}
}