// Dr66ListBoxDoc.h : CDr66ListBoxDoc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr66ListBoxDoc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr66ListBoxDoc();
	DECLARE_DYNCREATE(CDr66ListBoxDoc)

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
	virtual ~CDr66ListBoxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


