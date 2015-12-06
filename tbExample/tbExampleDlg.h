
// tbExampleDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include <list>

// CtbExampleDlg 对话框
class CtbExampleDlg : public CDialogEx
{
// 构造
public:
	CtbExampleDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TBEXAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	BOOL m_ieoc;
	CString m_search;
	CString m_describe;
	int m_sct;
	int m_set;
	CListBox m_output;
	void updateOutput(char * str);
	void begin_makemonkey(void);
	void end_makemonkey(void);
	CListCtrl m_listCtrl;
	void updateDeviceList(void);
	afx_msg void OnBnClickedButton1();
	CString m_address;
	float m_price;
	float m_postfee;
	std::list<std::string> m_devicelist;

	CRITICAL_SECTION lock;
	int ref;
	void resetRef();
	void incRef();
	void decRef();
	int getRef();
	int m_sct2;
	UINT m_times;
};
