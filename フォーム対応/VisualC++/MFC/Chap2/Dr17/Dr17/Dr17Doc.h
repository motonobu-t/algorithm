// Dr17Doc.h : CDr17Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr17Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr17Doc();
	DECLARE_DYNCREATE(CDr17Doc)

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
	virtual ~CDr17Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


