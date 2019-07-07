// ReadWriteTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ReadWriteTest.h"
#include "ReadWriteTestDlg.h"
#include "mwrf32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadWriteTestDlg dialog

CReadWriteTestDlg::CReadWriteTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReadWriteTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReadWriteTestDlg)
	m_Port = -1;
	m_Sector = 0;
	m_key = _T("");
	m_OpMode = -1;
	m_Data = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	icdev = NULL;
}

void CReadWriteTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReadWriteTestDlg)
	DDX_Control(pDX, IDC_KEY_MODE, m_KeyModeCtrl);
	DDX_Control(pDX, IDC_STATUS, m_Status);
	DDX_Control(pDX, IDC_COMBO_BAUND, m_BaundCtl);
	DDX_Radio(pDX, IDC_RADIO1, m_Port);
	DDX_Text(pDX, IDC_SECTOR, m_Sector);
	DDX_Text(pDX, IDC_EDIT8, m_key);
	DDV_MaxChars(pDX, m_key, 12);
	DDX_Radio(pDX, IDC_READBLOCK, m_OpMode);
	DDX_Text(pDX, IDC_DATA, m_Data);
	DDV_MaxChars(pDX, m_Data, 32);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReadWriteTestDlg, CDialog)
	//{{AFX_MSG_MAP(CReadWriteTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CONNECT, OnBtnConnect)
	ON_BN_CLICKED(IDC_BTN_DISCONNECT, OnBtnDisconnect)
	ON_BN_CLICKED(IDC_TEST, OnTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadWriteTestDlg message handlers

BOOL CReadWriteTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	m_Port = 0;
    m_BaundCtl.SetCurSel(6);
	m_OpMode = 0;
	m_KeyModeCtrl.SetCurSel(0);
	m_key = "FFFFFFFFFFFF";
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReadWriteTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CReadWriteTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CReadWriteTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReadWriteTestDlg::OnBtnConnect() 
{
	UpdateData(TRUE);

	__int16 st;
	unsigned char _Status[30];
	memset(_Status,0,30);

	m_baund = GetBaund();
	rf_exit(icdev);
	icdev = rf_init(m_Port,m_baund);
	st = rf_get_status(icdev,_Status);
	if(icdev<0 || st)
		m_Status.SetWindowText("连接失败!");
	else
	{
		rf_beep(icdev,10);
		m_Status.SetWindowText("连接成功!");
	}
	
	UpdateData(FALSE);
}

void CReadWriteTestDlg::OnBtnDisconnect() 
{
    __int16 st;
	
	if(icdev == NULL || icdev <0)
        m_Status.SetWindowText("端口未初始化!");

	st = rf_exit(icdev);
	if(st)
		m_Status.SetWindowText("断开连接失败!");
	else
		m_Status.SetWindowText("断开连接成功!");

	UpdateData(FALSE);
}

void CReadWriteTestDlg::OnTest() 
{
	UpdateData(TRUE);
	
	unsigned char Sec = m_Sector;
    __int16 st;
    unsigned __int16 TagType;
	unsigned long Snr;
	unsigned char Size;
    unsigned char data[33];
	memset(data,0,33);
	
	st = rf_reset(icdev,5);
	
	st = rf_request(icdev,1,&TagType);
	if(st)
	{
		m_Status.SetWindowText("寻卡失败!");
		return;
	}
	st = rf_anticoll(icdev,0, &Snr);
	if(st)
	{
		m_Status.SetWindowText("防冲突失败!");
		return;
	}
	st = rf_select(icdev,Snr,&Size);
	if(st)
	{
		m_Status.SetWindowText("选卡失败!");
		return;
	}
	unsigned char key[7];
	memset(key,0,7);
	a_hex(m_key.GetBuffer(12),key,12);
	m_key.ReleaseBuffer();
	unsigned char m_keymode;
	if(m_KeyModeCtrl.GetCurSel()==0)
		m_keymode = 0;
	else
		m_keymode = 4;
	st = rf_load_key(icdev,m_keymode,Sec,key);
	if(st)
	{
		m_Status.SetWindowText("装载密码失败!");
		return;
	}
	st = rf_authentication(icdev,m_keymode,Sec);
    if(st)
	{
		m_Status.SetWindowText("认证失败!");
		return;
	}
	if(m_OpMode == 0 )
	{
		unsigned char temp[33];
		memset(temp,0,33);
		
		
		if(m_OpMode == 0)
			st = rf_read(icdev,Sec*4,data);
		
		if(st)
		{
			m_Status.SetWindowText("读数据失败!");
			return;
		}
		hex_a(data,(char*)temp,16);
		m_Data.Format("%s",temp);
		
		
		m_Status.SetWindowText("读数据成功!");
	}
	else if(m_OpMode == 1)
	{
		if(m_Data == "" )
		{
			MessageBox("请确认是否有输入三个块的数据!","读写测试",MB_OK|MB_ICONWARNING);
			return;
		}
		unsigned char temp[33];
		memset(temp,0,33);
		memset(data,0,33);
		a_hex(m_Data.GetBuffer(32),temp,32);
		m_Data.ReleaseBuffer();
		memcpy(data,temp,16);
		
		if(m_OpMode == 1)
			st = rf_write(icdev,Sec*4,data);
		
		if(st)
		{
			m_Status.SetWindowText("写数据失败!");
			return;
		}
        
		m_Status.SetWindowText("写数据成功!");
	}
	rf_beep(icdev,10);
	
	UpdateData(FALSE);
	st = rf_halt(icdev);
}

long CReadWriteTestDlg::GetBaund()
{
	switch(m_BaundCtl.GetCurSel())
	{
	case 0:
		return 9600;
	case 1:
		return 14400;
	case 2:
		return 19200;
	case 3:
		return 28800;
	case 4:
		return 38400;
	case 5:
		return 57600;
	case 6:
		return 115200;
	}

    return 9600;
}


