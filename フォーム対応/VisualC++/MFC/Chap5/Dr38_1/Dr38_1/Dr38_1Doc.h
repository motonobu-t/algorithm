// Dr38_1Doc.h : CDr38_1Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr38_1Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr38_1Doc();
	DECLARE_DYNCREATE(CDr38_1Doc)

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
	virtual ~CDr38_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


