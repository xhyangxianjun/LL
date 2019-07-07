// ReadWriteTest.h : main header file for the READWRITETEST application
//

#if !defined(AFX_READWRITETEST_H__A0839105_B418_11D6_A0F0_00E01808B099__INCLUDED_)
#define AFX_READWRITETEST_H__A0839105_B418_11D6_A0F0_00E01808B099__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReadWriteTestApp:
// See ReadWriteTest.cpp for the implementation of this class
//

class CReadWriteTestApp : public CWinApp
{
public:
	CReadWriteTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadWriteTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReadWriteTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READWRITETEST_H__A0839105_B418_11D6_A0F0_00E01808B099__INCLUDED_)
