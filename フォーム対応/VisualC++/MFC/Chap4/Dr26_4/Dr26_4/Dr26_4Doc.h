// Dr26_4Doc.h : CDr26_4Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr26_4Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr26_4Doc();
	DECLARE_DYNCREATE(CDr26_4Doc)

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
	virtual ~CDr26_4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


