#pragma once
#include "Effect.h"
#include "Include.h"

#include "RcParticle.h"
#include "Transform.h"
#include "Shader.h"
#include "Texture.h"

using namespace Engine;

class CEffect_RcParticle final : public CEffect
{
private:
	explicit CEffect_RcParticle(LPDIRECT3DDEVICE9 pGraphicDev, const FX_INFO& tInfo, const PARTICLE_INFO& tParticleInfo, const _bool& bLoop);
	virtual ~CEffect_RcParticle();

public:
	virtual void Activate_Effect(const _matrix* pMatParent) override;
	virtual void Refresh_Effect(const _matrix* pMatParent) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Deactivate_Effect();
	virtual void Render_Object(void) override;
	virtual void Update_Matrix() {};


private:
	HRESULT Add_Component(const _tchar* szTexTag);
	HRESULT SetUp_ConstantTable(LPD3DXEFFECT pEffect);
	HRESULT Ready_Effect(const _tchar* szTexTag);

	void Update_Particle(const _float& fTimeDelta);
	_matrix Update_ParticleMatrix(const FX_INFO& tFXInfo);
	void Ready_Particle(FX_INFO& tFXInfo);

private:
	_vec3  Get_RandVector3(const _vec3* vArr);
	_float Get_RandFloat(const _float* fArr);
	_int   Get_RandNum(const _int* iArr, _bool bReturnUnsigned = false);


private: //Components
	CRenderer*			m_pRenderer = nullptr;
	CRcParticle*		m_pBufferCom = nullptr;
	CTransform*			m_pTransCom = nullptr;
	CTexture*			m_pTextureCom = nullptr;
	CShader*			m_pShaderCom = nullptr;

private:
	PARTICLE_INFO		m_tParticleInfo;
	list<FX_INFO>		m_lstFXInfo;

	_bool				m_bLoopParticle = false;
	_bool				m_bLoopEnd = false;
	_uint				m_dwAliveCnt = 0;
		

public:
	static CEffect_RcParticle* Create(LPDIRECT3DDEVICE9 pGraphicDev, const FX_INFO& tInfo, const PARTICLE_INFO& tParticleInfo, const _tchar* szTexTag, const _bool& bLoop = false);
	virtual void Free(void) override;

};

