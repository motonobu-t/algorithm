// Dr50_2Doc.h : CDr50_2Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr50_2Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr50_2Doc();
	DECLARE_DYNCREATE(CDr50_2Doc)

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
	virtual ~CDr50_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


