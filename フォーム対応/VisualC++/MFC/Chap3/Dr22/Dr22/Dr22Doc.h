// Dr22Doc.h : CDr22Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr22Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr22Doc();
	DECLARE_DYNCREATE(CDr22Doc)

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
	virtual ~CDr22Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


