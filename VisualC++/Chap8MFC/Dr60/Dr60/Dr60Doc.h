// Dr60Doc.h : CDr60Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr60Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr60Doc();
	DECLARE_DYNCREATE(CDr60Doc)

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
	virtual ~CDr60Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


