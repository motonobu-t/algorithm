// Rei17Doc.h : CRei17Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei17Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei17Doc();
	DECLARE_DYNCREATE(CRei17Doc)

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
	virtual ~CRei17Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


