// Rei42Doc.h : CRei42Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei42Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei42Doc();
	DECLARE_DYNCREATE(CRei42Doc)

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
	virtual ~CRei42Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


