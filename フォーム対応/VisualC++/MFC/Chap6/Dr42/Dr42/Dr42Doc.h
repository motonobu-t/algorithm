// Dr42Doc.h : CDr42Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr42Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr42Doc();
	DECLARE_DYNCREATE(CDr42Doc)

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
	virtual ~CDr42Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


