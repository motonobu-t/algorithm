// Dr20_3Doc.h : CDr20_3Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr20_3Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr20_3Doc();
	DECLARE_DYNCREATE(CDr20_3Doc)

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
	virtual ~CDr20_3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


