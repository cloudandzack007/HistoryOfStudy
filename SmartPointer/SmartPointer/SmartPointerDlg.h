
// SmartPointerDlg.h : 头文件
//

#pragma once



// CSmartPointerDlg 对话框
class CSmartPointerDlg : public CDialogEx
{
// 构造
public:
	CSmartPointerDlg(CWnd* pParent = NULL);	// 标准构造函数
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SMARTPOINTER_DIALOG };
#endif

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

class Stub
{
public:
	void print()
	{
		return;
	}
	Stub()
	{
		flag = rand();
	}
	~Stub()
	{
		return;
	}
private:
	int flag;
};
template<typename T>
class SmartPtr
{
public:
	SmartPtr(T*p = 0) :ptr(p), pUse(new size_t(1))
	{
	}

	SmartPtr(const SmartPtr& src) :ptr(src.ptr), pUse(src.pUse)
	{
		++*pUse;
	}

	SmartPtr& operator = (const SmartPtr& rhs)
	{
		++*rhs.pUse;
		decrUse();
		ptr = rhs.ptr;
		pUse = rhs.pUse;
		return *this;
	}

	T* operator->()
	{
		if (ptr)
			return ptr;
	}

	const T* operator->()const
	{
		if (ptr)
			return ptr;
	}
	T &operator*()
	{
		if (ptr)
			return *ptr;
	}
	const T &operator*()const
	{
		if (ptr)
			return *ptr;
	}
	~SmartPtr()
	{
		decrUse();
	}
private:
	void decrUse()
	{
		if (--*pUse == 0)
		{
			delete ptr;
			delete pUse;
		}
	}
	T* ptr;
	size_t* pUse;
};


