
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
	, m_address(_T(""))
	, m_price(0)
	, m_postfee(0)
	, m_sct2(0)
	, m_times(0)
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
	DDX_Control(pDX, IDC_LIST3, m_listCtrl);
	DDX_Text(pDX, IDC_EDIT5, m_address);
	DDX_Text(pDX, IDC_EDIT6, m_price);
	DDX_Text(pDX, IDC_EDIT7, m_postfee);
	DDX_Text(pDX, IDC_EDIT8, m_sct2);
	DDV_MinMaxInt(pDX, m_sct2, 0, 100);
	DDX_Text(pDX, IDC_EDIT9, m_times);
	DDV_MinMaxUInt(pDX, m_times, 1, 1000);
}

BEGIN_MESSAGE_MAP(CtbExampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CtbExampleDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CtbExampleDlg::OnBnClickedButton1)
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
	m_sct2 = 10;
	m_address = "";
	m_postfee = m_price = -1;
	m_times = 1;

	UpdateData(FALSE);


	LONG lStyle;
	lStyle = GetWindowLong(m_listCtrl.m_hWnd, GWL_STYLE);//��ȡ��ǰ����style
	lStyle &= ~LVS_TYPEMASK; //�����ʾ��ʽλ
	lStyle |= LVS_REPORT; //����style
	SetWindowLong(m_listCtrl.m_hWnd, GWL_STYLE, lStyle);//����style

	DWORD dwStyle = m_listCtrl.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl��
	dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ�
	m_listCtrl.SetExtendedStyle(dwStyle); //������չ���

	m_listCtrl.InsertColumn( 0, "�豸����", LVCFMT_LEFT, 226 );//������

	updateDeviceList();

	::InitializeCriticalSection(&lock); 

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

typedef char * (*fun1)(char *);
typedef char * (*fun2)(char *, char *);
typedef char * (*fun3)(char *, int);
typedef int (*fun4)(char *);
typedef char * (*fun5)(char * device, char * arg, char * address, float price, float postfee, bool go_on);
typedef int (* getDevices)(std::list<std::string> * );
typedef bool (* fun6)(char * device);

void updateOutput(char * device, char * str, char * str2)
{
	CtbExampleDlg * dlg = (CtbExampleDlg*)AfxGetApp()->GetMainWnd();

	char tmp[256] = {0};
	sprintf_s(tmp, 256, "%s:%s -> result : %s", device, str, str2);

	dlg->updateOutput(tmp);
}

void * thread_fun(void * param)
{
	CtbExampleDlg * dlg = (CtbExampleDlg*)AfxGetApp()->GetMainWnd();
	dlg->UpdateData();
	dlg->begin_makemonkey();

	int index = (int)param;
	if((int)dlg->m_devicelist.size() <= index)
	{
		AfxMessageBox(" �Ҳ����豸���ţ�");

		dlg->end_makemonkey();
	}

	std::string device;
	int i = 0;
	for(std::list<std::string>::iterator it = dlg->m_devicelist.begin(); it != dlg->m_devicelist.end(); it++, i++)
		if(index == i)
			device = *it;

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
	fun5 entrySearchResultActivity = (fun5)::GetProcAddress(handle, "entrySearchResultActivity");
	fun3 entryCommodityActivity = (fun3)::GetProcAddress(handle, "entryCommodityActivity");
	fun3 entryEvaluationActivity = (fun3)::GetProcAddress(handle, "entryEvaluationActivity");
	fun1 entryCommodityActivityRandomly = (fun1)::GetProcAddress(handle, "entryCommodityActivityRandomly");
	fun1 exitCommodityActivity = (fun1)::GetProcAddress(handle, "exitCommodityActivity");
	fun1 exitShopActivity = (fun1)::GetProcAddress(handle, "exitShopActivity");
	fun1 exitSearchResultActivity = (fun1)::GetProcAddress(handle, "exitSearchResultActivity");
	fun1 exitSearchConditionActivity = (fun1)::GetProcAddress(handle, "exitSearchConditionActivity");
	fun1 exitMainActivity = (fun1)::GetProcAddress(handle, "exitMainActivity");
	fun6 isInstallSpecialInput = (fun6)::GetProcAddress(handle, "isInstallSpecialInput");

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
		!exitMainActivity ||
		!isInstallSpecialInput
		)
	{
		AfxMessageBox("������ʼ��ʧ�ܣ�");
		::FreeLibrary(handle);

		dlg->end_makemonkey();

		return 0;
	}

	initial((char *)device.c_str());

	updateOutput((char *)device.c_str(), "ERROR ", "���ר�����뷨�Ƿ�װ!");
	if(!isInstallSpecialInput((char *)device.c_str()))
	{
		updateOutput((char *)device.c_str(), "ERROR ", "δ��װר�����뷨!");
		return 0;
	}
	updateOutput((char *)device.c_str(), "ERROR ", "ר�����뷨�Ѱ�װ!");

	UINT times = dlg->m_times;
	while(times --)
	{
		do
		{	
			stroutput = startTaobao((char *)device.c_str());
			updateOutput((char *)device.c_str(), "startTaobao", stroutput);
			if(strncmp(stroutput, "good", 4) != 0)
			{
				updateOutput((char *)device.c_str(), "ERROR ", "break process!");
				break;
			}

			stroutput = entryMainActivity((char *)device.c_str());
			updateOutput((char *)device.c_str(), "entryMainActivity", stroutput);
			if(strncmp(stroutput, "good", 4) != 0)
			{
				updateOutput((char *)device.c_str(), "ERROR ", "break process!");
				break;
			}

			stroutput = entrySearchConditionActivity((char *)device.c_str(), dlg->m_search.GetBuffer(0));
			updateOutput((char *)device.c_str(), "entrySearchConditionActivity", stroutput);
			if(strncmp(stroutput, "good", 4) != 0)
			{
				updateOutput((char *)device.c_str(), "ERROR ", "break process!");
				break;
			}

			stroutput = entrySearchResultActivity((char *)device.c_str(), dlg->m_describe.GetBuffer(0), dlg->m_address.IsEmpty() ? NULL:dlg->m_address.GetBuffer(0), dlg->m_price, dlg->m_postfee, true);
			updateOutput((char *)device.c_str(), "entrySearchResultActivity", stroutput);
			if(strncmp(stroutput, "good", 4) != 0)
			{
				updateOutput((char *)device.c_str(), "ERROR ", "break process!");
				break;
			}

			stroutput = entryCommodityActivity((char *)device.c_str(), dlg->m_sct);
			updateOutput((char *)device.c_str(), "entryCommodityActivity", stroutput);
			if(strncmp(stroutput, "good", 4) != 0)
			{
				updateOutput((char *)device.c_str(), "ERROR ", "break process!");
				break;
			}

			stroutput = entryEvaluationActivity((char *)device.c_str(), dlg->m_set);
			updateOutput((char *)device.c_str(), "entryEvaluationActivity", stroutput);
			if(strncmp(stroutput, "good", 4) != 0)
			{
				updateOutput((char *)device.c_str(), "ERROR ", "break process!");
				break;
			}

			if(dlg->m_ieoc)
			{
				stroutput = entryCommodityActivityRandomly((char *)device.c_str());
				updateOutput((char *)device.c_str(), "entryCommodityActivityRandomly", stroutput);
				if(strncmp(stroutput, "good", 4) != 0)
				{
					updateOutput((char *)device.c_str(), "ERROR ", "break process!");
					break;
				}

				stroutput = entryCommodityActivity((char *)device.c_str(), dlg->m_sct2);
				updateOutput((char *)device.c_str(), "entryCommodityActivity", stroutput);
				if(strncmp(stroutput, "good", 4) != 0)
				{
					updateOutput((char *)device.c_str(), "ERROR ", "break process!");
					break;
				}

				stroutput = exitCommodityActivity((char *)device.c_str());
				updateOutput((char *)device.c_str(), "exitCommodityActivity", stroutput);
				if(strncmp(stroutput, "good", 4) != 0)
				{
					updateOutput((char *)device.c_str(), "ERROR ", "break process!");
					break;
				}

				stroutput = exitShopActivity((char *)device.c_str());
				updateOutput((char *)device.c_str(), "exitShopActivity", stroutput);
				if(strncmp(stroutput, "good", 4) != 0)
				{
					updateOutput((char *)device.c_str(), "ERROR ", "break process!");
					break;
				}
			}

			stroutput = exitCommodityActivity((char *)device.c_str());
			updateOutput((char *)device.c_str(), "exitCommodityActivity", stroutput);
			if(strncmp(stroutput, "good", 4) != 0)
			{
				updateOutput((char *)device.c_str(), "ERROR ", "break process!");
				break;
			}

			stroutput = exitSearchResultActivity((char *)device.c_str());
			updateOutput((char *)device.c_str(), "exitSearchResultActivity", stroutput);
			if(strncmp(stroutput, "good", 4) != 0)
			{
				updateOutput((char *)device.c_str(), "ERROR ", "break process!");
				break;
			}

			stroutput = exitSearchConditionActivity((char *)device.c_str());
			updateOutput((char *)device.c_str(), "exitSearchConditionActivity", stroutput);
			if(strncmp(stroutput, "good", 4) != 0)
			{
				updateOutput((char *)device.c_str(), "ERROR ", "break process!");
				break;
			}

			stroutput = exitMainActivity((char *)device.c_str());
			updateOutput((char *)device.c_str(), "exitMainActivity", stroutput);
			if(strncmp(stroutput, "good", 4) != 0)
			{
				updateOutput((char *)device.c_str(), "ERROR ", "break process!");
				break;
			}
		}while(false);

		stroutput = stopTaobao((char *)device.c_str());
		updateOutput((char *)device.c_str(), "stopTaobao", stroutput);
	}

	::FreeLibrary(handle);

	dlg->end_makemonkey();

	return 0;
}

void CtbExampleDlg::OnBnClickedOk()
{
	UpdateData();
	updateDeviceList();
	
	resetRef();
	for(int i = 0; i < (int)m_devicelist.size(); i++)
		::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_fun, (void *)i, 0, 0);
}

void CtbExampleDlg::resetRef()
{
	::EnterCriticalSection(&lock);
	ref = 0;
	::LeaveCriticalSection(&lock);
}
void CtbExampleDlg::incRef()
{
	::EnterCriticalSection(&lock);
	ref ++;
	::LeaveCriticalSection(&lock);
}

void CtbExampleDlg::decRef()
{
	::EnterCriticalSection(&lock);
	ref --;
	::LeaveCriticalSection(&lock);
}

int CtbExampleDlg::getRef()
{
	int val = 0;
	::EnterCriticalSection(&lock);
	val = ref;
	::LeaveCriticalSection(&lock);

	return val;
}

void CtbExampleDlg::updateOutput(char * str)
{
	m_output.AddString(str);
	m_output.SetCurSel(m_output.GetCount() - 1);
}


void CtbExampleDlg::begin_makemonkey(void)
{
	incRef();

	if(getRef() > 0)
		GetDlgItem(IDOK)->EnableWindow(FALSE);
}


void CtbExampleDlg::end_makemonkey(void)
{
	decRef();

	if(getRef() == 0)
		GetDlgItem(IDOK)->EnableWindow(TRUE);
}


void CtbExampleDlg::updateDeviceList(void)
{
	m_devicelist.clear();
	m_listCtrl.DeleteAllItems();

	char curpath[MAX_PATH] = {0};
	GetCurrentDirectory(MAX_PATH, curpath);

	//���춯̬���ַ
	char dllpath[MAX_PATH] = {0};
	sprintf_s(dllpath, MAX_PATH, "%s\\tbInterface.dll", curpath);
	HMODULE handle = ::LoadLibrary(dllpath);
	if(handle == NULL)
	{
		AfxMessageBox("��̬�����ʧ�ܣ�");
		return ;
	}

	getDevices gd = (getDevices)::GetProcAddress(handle, "getDevices");
	if(gd == NULL)
	{
		AfxMessageBox("getDevices ��ȡʧ�ܣ�");
		return ;
	}

	int ret = gd(&m_devicelist);
	if(ret < 0)
	{
		CString tmp;
		tmp.Format("getDevices ����ʧ�ܣ�ret = %d", ret);
		AfxMessageBox(tmp);

		return ;
	}

	std::list<std::string>::iterator it = m_devicelist.begin();
	for(int i = 0; i < (int)m_devicelist.size(); i++, it++)
		m_listCtrl.InsertItem(i, (*it).c_str());//������

	::FreeLibrary(handle);
}


void CtbExampleDlg::OnBnClickedButton1()
{
	updateDeviceList();
}
