// rei54Doc.h : Crei54Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class Crei54Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	Crei54Doc();
	DECLARE_DYNCREATE(Crei54Doc)

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
	virtual ~Crei54Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


