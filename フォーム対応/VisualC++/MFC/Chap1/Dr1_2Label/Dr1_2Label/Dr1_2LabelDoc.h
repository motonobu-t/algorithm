// Dr1_2LabelDoc.h : CDr1_2LabelDoc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr1_2LabelDoc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr1_2LabelDoc();
	DECLARE_DYNCREATE(CDr1_2LabelDoc)

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
	virtual ~CDr1_2LabelDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


