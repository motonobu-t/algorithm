// Dr5Doc.h : CDr5Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr5Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr5Doc();
	DECLARE_DYNCREATE(CDr5Doc)

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
	virtual ~CDr5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


