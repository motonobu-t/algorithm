// Dr18_2Doc.h : CDr18_2Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr18_2Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr18_2Doc();
	DECLARE_DYNCREATE(CDr18_2Doc)

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
	virtual ~CDr18_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


