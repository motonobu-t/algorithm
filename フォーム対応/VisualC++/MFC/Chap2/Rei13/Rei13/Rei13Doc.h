// Rei13Doc.h : CRei13Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei13Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei13Doc();
	DECLARE_DYNCREATE(CRei13Doc)

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
	virtual ~CRei13Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


