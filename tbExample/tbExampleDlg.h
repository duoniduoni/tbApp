
// tbExampleDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CtbExampleDlg �Ի���
class CtbExampleDlg : public CDialogEx
{
// ����
public:
	CtbExampleDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TBEXAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
};
