// Dr17MFCDoc.h : CDr17MFCDoc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr17MFCDoc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr17MFCDoc();
	DECLARE_DYNCREATE(CDr17MFCDoc)

// ����
public:

// ����
public:

// �I�[�o�[���C�h
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ����
public:
	virtual ~CDr17MFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


