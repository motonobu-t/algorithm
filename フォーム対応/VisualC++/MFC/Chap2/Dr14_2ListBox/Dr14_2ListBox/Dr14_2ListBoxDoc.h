// Dr14_2ListBoxDoc.h : CDr14_2ListBoxDoc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr14_2ListBoxDoc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr14_2ListBoxDoc();
	DECLARE_DYNCREATE(CDr14_2ListBoxDoc)

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
	virtual ~CDr14_2ListBoxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


