// Rei24Doc.h : CRei24Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei24Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei24Doc();
	DECLARE_DYNCREATE(CRei24Doc)

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
	virtual ~CRei24Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


