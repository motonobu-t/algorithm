// Rei48Doc.h : CRei48Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei48Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei48Doc();
	DECLARE_DYNCREATE(CRei48Doc)

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
	virtual ~CRei48Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


