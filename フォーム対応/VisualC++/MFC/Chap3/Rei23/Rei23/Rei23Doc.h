// Rei23Doc.h : CRei23Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei23Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei23Doc();
	DECLARE_DYNCREATE(CRei23Doc)

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
	virtual ~CRei23Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


