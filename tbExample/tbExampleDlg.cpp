
// tbExampleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "tbExample.h"
#include "tbExampleDlg.h"
#include "afxdialogex.h"

#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtbExampleDlg �Ի���



CtbExampleDlg::CtbExampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtbExampleDlg::IDD, pParent)
	, m_ieoc(FALSE)
	, m_search(_T(""))
	, m_describe(_T(""))
	, m_sct(0)
	, m_set(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtbExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_ieoc);
	DDX_Text(pDX, IDC_EDIT1, m_search);
	DDV_MaxChars(pDX, m_search, 60);
	DDX_Text(pDX, IDC_EDIT2, m_describe);
	DDV_MaxChars(pDX, m_describe, 100);
	DDX_Text(pDX, IDC_EDIT3, m_sct);
	DDV_MinMaxInt(pDX, m_sct, 1, 60);
	DDX_Text(pDX, IDC_EDIT4, m_set);
	DDV_MinMaxInt(pDX, m_set, 1, 60);
	DDX_Control(pDX, IDC_LIST1, m_output);
}

BEGIN_MESSAGE_MAP(CtbExampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CtbExampleDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CtbExampleDlg ��Ϣ�������

BOOL CtbExampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_search = "KAMJOVE\\#TP\\#160";
	m_describe = "����\\#TP-160\\#���Ȳ���\\#��ѹʽ\\#Ʈ�ݱ�\\#TP-160\\#�����";
	m_ieoc = TRUE;
	m_sct = 20;
	m_set = 10;

	UpdateData(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CtbExampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtbExampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtbExampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

typedef char * (*fun1)();
typedef char * (*fun2)(char *);
typedef char * (*fun3)(int);
typedef int (*fun4)();

void updateOutput(char * str, char * str2)
{
	CtbExampleDlg * dlg = (CtbExampleDlg*)AfxGetApp()->GetMainWnd();

	char tmp[256] = {0};
	sprintf_s(tmp, 256, "%s -> result : %s", str, str2);

	dlg->updateOutput(tmp);
}

void * thread_fun(void * param)
{
	CtbExampleDlg * dlg = (CtbExampleDlg*)AfxGetApp()->GetMainWnd();
	dlg->UpdateData();

	dlg->begin_makemonkey();

	char curpath[MAX_PATH] = {0};
	GetCurrentDirectory(MAX_PATH, curpath);

	//���춯̬���ַ
	char dllpath[MAX_PATH] = {0};
	sprintf_s(dllpath, MAX_PATH, "%s\\tbInterface.dll", curpath);
	HMODULE handle = ::LoadLibrary(dllpath);
	if(handle == NULL)
	{
		AfxMessageBox("��̬�����ʧ�ܣ�");

		dlg->end_makemonkey();

		return 0;
	}

	char *stroutput;
	fun4 initial = (fun4)::GetProcAddress(handle, "initial");
	fun1 startTaobao = (fun1)::GetProcAddress(handle, "startTaobao");
	fun1 stopTaobao = (fun1)::GetProcAddress(handle, "stopTaobao");
	fun1 entryMainActivity = (fun1)::GetProcAddress(handle, "entryMainActivity");
	fun2 entrySearchConditionActivity = (fun2)::GetProcAddress(handle, "entrySearchConditionActivity");
	fun2 entrySearchResultActivity = (fun2)::GetProcAddress(handle, "entrySearchResultActivity");
	fun3 entryCommodityActivity = (fun3)::GetProcAddress(handle, "entryCommodityActivity");
	fun3 entryEvaluationActivity = (fun3)::GetProcAddress(handle, "entryEvaluationActivity");
	fun1 entryCommodityActivityRandomly = (fun1)::GetProcAddress(handle, "entryCommodityActivityRandomly");
	fun1 exitCommodityActivity = (fun1)::GetProcAddress(handle, "exitCommodityActivity");
	fun1 exitShopActivity = (fun1)::GetProcAddress(handle, "exitShopActivity");
	fun1 exitSearchResultActivity = (fun1)::GetProcAddress(handle, "exitSearchResultActivity");
	fun1 exitSearchConditionActivity = (fun1)::GetProcAddress(handle, "exitSearchConditionActivity");
	fun1 exitMainActivity = (fun1)::GetProcAddress(handle, "exitMainActivity");

	if( 
		!initial ||
		!startTaobao ||
		!stopTaobao ||
		!entryMainActivity ||
		!entrySearchConditionActivity ||
		!entrySearchResultActivity ||
		!entryCommodityActivity ||
		!entryEvaluationActivity ||
		!entryCommodityActivityRandomly || 
		!exitCommodityActivity ||
		!exitShopActivity ||
		!exitSearchResultActivity ||
		!exitSearchConditionActivity ||
		!exitMainActivity
		)
	{
		AfxMessageBox("������ʼ��ʧ�ܣ�");
		::FreeLibrary(handle);

		dlg->end_makemonkey();

		return 0;
	}

	initial();

	stroutput = startTaobao();
	updateOutput("startTaobao", stroutput);

	do
	{
	stroutput = entryMainActivity();
	updateOutput("entryMainActivity", stroutput);
	if(strncmp(stroutput, "good", 4) != 0)
	{
		updateOutput("ERROR ", "break process!");
		break;
	}

	stroutput = entrySearchConditionActivity(dlg->m_search.GetBuffer(0));
	updateOutput("entrySearchConditionActivity", stroutput);
	if(strncmp(stroutput, "good", 4) != 0)
	{
		updateOutput("ERROR ", "break process!");
		break;
	}

	stroutput = entrySearchResultActivity(dlg->m_describe.GetBuffer(0));
	updateOutput("entrySearchResultActivity", stroutput);
	if(strncmp(stroutput, "good", 4) != 0)
	{
		updateOutput("ERROR ", "break process!");
		break;
	}

	stroutput = entryCommodityActivity(dlg->m_sct);
	updateOutput("entryCommodityActivity", stroutput);
	if(strncmp(stroutput, "good", 4) != 0)
	{
		updateOutput("ERROR ", "break process!");
		break;
	}

	stroutput = entryEvaluationActivity(dlg->m_set);
	updateOutput("entryEvaluationActivity", stroutput);
	if(strncmp(stroutput, "good", 4) != 0)
	{
		updateOutput("ERROR ", "break process!");
		break;
	}

	if(dlg->m_ieoc)
	{
		stroutput = entryCommodityActivityRandomly();
		updateOutput("entryCommodityActivityRandomly", stroutput);
		if(strncmp(stroutput, "good", 4) != 0)
		{
			updateOutput("ERROR ", "break process!");
			break;
		}

		stroutput = entryCommodityActivity(2);
		updateOutput("entryCommodityActivity", stroutput);
		if(strncmp(stroutput, "good", 4) != 0)
		{
			updateOutput("ERROR ", "break process!");
			break;
		}

		stroutput = exitCommodityActivity();
		updateOutput("exitCommodityActivity", stroutput);
		if(strncmp(stroutput, "good", 4) != 0)
		{
			updateOutput("ERROR ", "break process!");
			break;
		}

		stroutput = exitShopActivity();
		updateOutput("exitShopActivity", stroutput);
		if(strncmp(stroutput, "good", 4) != 0)
		{
			updateOutput("ERROR ", "break process!");
			break;
		}
	}

	stroutput = exitCommodityActivity();
	updateOutput("exitCommodityActivity", stroutput);
	if(strncmp(stroutput, "good", 4) != 0)
	{
		updateOutput("ERROR ", "break process!");
		break;
	}

	stroutput = exitSearchResultActivity();
	updateOutput("exitSearchResultActivity", stroutput);
	if(strncmp(stroutput, "good", 4) != 0)
	{
		updateOutput("ERROR ", "break process!");
		break;
	}

	stroutput = exitSearchConditionActivity();
	updateOutput("exitSearchConditionActivity", stroutput);
	if(strncmp(stroutput, "good", 4) != 0)
	{
		updateOutput("ERROR ", "break process!");
		break;
	}

	stroutput = exitMainActivity();
	updateOutput("exitMainActivity", stroutput);
	if(strncmp(stroutput, "good", 4) != 0)
	{
		updateOutput("ERROR ", "break process!");
		break;
	}
	}while(false);

	stroutput = stopTaobao();
	updateOutput("stopTaobao", stroutput);

	::FreeLibrary(handle);

	dlg->end_makemonkey();

	return 0;
}

void CtbExampleDlg::OnBnClickedOk()
{
	UpdateData();
	
	::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_fun, 0, 0, 0);
	
//	CDialogEx::OnOK();
}


void CtbExampleDlg::updateOutput(char * str)
{
	m_output.AddString(str);
	m_output.SetCurSel(m_output.GetCount() - 1);
}


void CtbExampleDlg::begin_makemonkey(void)
{
	GetDlgItem(IDOK)->EnableWindow(FALSE);
}


void CtbExampleDlg::end_makemonkey(void)
{
	GetDlgItem(IDOK)->EnableWindow(TRUE);
}
