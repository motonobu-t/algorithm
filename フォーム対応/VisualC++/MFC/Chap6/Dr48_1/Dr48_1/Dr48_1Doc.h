// Dr48_1Doc.h : CDr48_1Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr48_1Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr48_1Doc();
	DECLARE_DYNCREATE(CDr48_1Doc)

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
	virtual ~CDr48_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


