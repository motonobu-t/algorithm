// Dr64Doc.h : CDr64Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr64Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr64Doc();
	DECLARE_DYNCREATE(CDr64Doc)

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
	virtual ~CDr64Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


