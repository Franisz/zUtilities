#include <UnionAfx.h>

namespace SystemPack
{
	CArray<CMemPage*> CMemPage::arrPages;

	CMemPage::CMemPage ()
	{
		arrPages.Insert( this );
	}

	CMemPage* CMemPage::GetPage (const uint32& index)
	{
		for (uint32 i = 0; i < arrPages.GetNum(); i++)
		{
			if( arrPages[i]->ulIndex == index )
			{
				return arrPages[i];
			}
		}
		return Null;
	}

	CMemPage* CMemPage::Allocate (const uint32& index, const uint32& size)
	{
		CMemPage* pMemPage = GetPage( index );
		if( pMemPage )
		{
			if( pMemPage->ulSize == size )
			{
				return pMemPage;
			}
			//real32 fRate1 = ceilf( (real32)size / 4096.0 );
			//real32 fRate2 = ceilf( (real32)pMemPage->ulSize / 4096.0 );
		}
		ASSERT( !pMemPage, "Страница памяти index[" + CString(index, 16) + "] уже существует" );

		uint32 ulAddress = (uint32)VirtualAlloc( Null, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE );
		ASSERT( ulAddress, "Невозможно получить страницу памяти index[" + CString(index, 16) + "] size[" + CString(size, 16) + "]" );

		CMemPage* pPage = new CMemPage;
		pPage->ulAddress = ulAddress;
		pPage->ulIndex	 = index;
		pPage->ulSize	 = size;

		memset( (void32)ulAddress, 0, size );

		//MEMORY_BASIC_INFORMATION mbInfo;
		//VirtualQuery( (void32)ulAddress, &mbInfo, sizeof( MEMORY_BASIC_INFORMATION ));

		return pPage;
	}

	void CMemPage::Free (const uint32& index)
	{
		for (uint32 i = 0; i < arrPages.GetNum(); i++)
		{
			if( arrPages[i]->ulIndex == index )
			{
				delete arrPages[i];
				break;
			}
		}
	}

	uint32 CMemPage::GetIndex ()
	{
		return ulIndex;
	}

	uint32 CMemPage::GetSize ()
	{
		return ulSize;
	}

	uint32 CMemPage::GetAddress ()
	{
		return ulAddress;
	}


	CMemPage::~CMemPage ()
	{
		VirtualFree( (void32)ulAddress, 0, MEM_RELEASE );
		arrPages.Remove( this );
	}
}