// Dr13Doc.h : CDr13Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr13Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr13Doc();
	DECLARE_DYNCREATE(CDr13Doc)

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
	virtual ~CDr13Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


