// Dr59Doc.h : CDr59Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr59Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr59Doc();
	DECLARE_DYNCREATE(CDr59Doc)

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
	virtual ~CDr59Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


