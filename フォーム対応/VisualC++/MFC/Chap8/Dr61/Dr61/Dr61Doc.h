// Dr61Doc.h : CDr61Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr61Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr61Doc();
	DECLARE_DYNCREATE(CDr61Doc)

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
	virtual ~CDr61Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


