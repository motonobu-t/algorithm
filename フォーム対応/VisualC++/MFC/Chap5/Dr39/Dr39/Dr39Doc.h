// Dr39Doc.h : CDr39Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr39Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr39Doc();
	DECLARE_DYNCREATE(CDr39Doc)

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
	virtual ~CDr39Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


