// Rei34Doc.h : CRei34Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei34Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei34Doc();
	DECLARE_DYNCREATE(CRei34Doc)

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
	virtual ~CRei34Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


