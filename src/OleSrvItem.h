// OleSrvItem.h : interface of the CWinProMoOleSrvItem class
//

class CWinProMoOleSrvItem : public COleServerItem
{
	DECLARE_DYNAMIC(CWinProMoOleSrvItem)

// Constructors
public:
	CWinProMoOleSrvItem(CWinProMoDoc* pContainerDoc);

// Attributes
	CWinProMoDoc* GetDocument() const
		{ return (CWinProMoDoc*)COleServerItem::GetDocument(); }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleTestSrvrItem)
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CWinProMoOleSrvItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

/////////////////////////////////////////////////////////////////////////////
