/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
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
	//{{AFX_VIRTUAL(CWinProMoOleSrvItem)
public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	//}}AFX_VIRTUAL

// Implementation
public:
	~CWinProMoOleSrvItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


	// Generated message map functions
protected:
	//{{AFX_MSG(CWinProMoOleSrvItem)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
