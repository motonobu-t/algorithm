// Rei6Doc.h : CRei6Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei6Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei6Doc();
	DECLARE_DYNCREATE(CRei6Doc)

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
	virtual ~CRei6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


