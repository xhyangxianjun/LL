// ReadWriteTestDlg.h : header file
//

#if !defined(AFX_READWRITETESTDLG_H__A0839107_B418_11D6_A0F0_00E01808B099__INCLUDED_)
#define AFX_READWRITETESTDLG_H__A0839107_B418_11D6_A0F0_00E01808B099__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReadWriteTestDlg dialog

class CReadWriteTestDlg : public CDialog
{
public:
	long m_baund;
	HANDLE icdev;
public:
// Construction
public:
	CReadWriteTestDlg(CWnd* pParent = NULL);	// standard constructor
    long GetBaund();
// Dialog Data
	//{{AFX_DATA(CReadWriteTestDlg)
	enum { IDD = IDD_READWRITETEST_DIALOG };
	CComboBox	m_KeyModeCtrl;
	CStatic	m_Status;
	CComboBox	m_BaundCtl;
	int		m_Port;
	int		m_Sector;
	CString	m_key;
	int		m_OpMode;
	CString	m_Data;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadWriteTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReadWriteTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnConnect();
	afx_msg void OnBtnDisconnect();
	afx_msg void OnTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READWRITETESTDLG_H__A0839107_B418_11D6_A0F0_00E01808B099__INCLUDED_)
