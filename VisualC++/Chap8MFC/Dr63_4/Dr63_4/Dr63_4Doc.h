// Dr63_4Doc.h : CDr63_4Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr63_4Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr63_4Doc();
	DECLARE_DYNCREATE(CDr63_4Doc)

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
	virtual ~CDr63_4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

