// Dr47Doc.h : CDr47Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr47Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr47Doc();
	DECLARE_DYNCREATE(CDr47Doc)

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
	virtual ~CDr47Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


