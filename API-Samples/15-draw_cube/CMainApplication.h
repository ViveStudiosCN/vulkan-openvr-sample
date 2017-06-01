#include <openvr.h>

#include "Matrices.h"

class CMainApplication
{
public:
	CMainApplication(int argc, char *argv[]);
	virtual ~CMainApplication();

	bool BInit();
	bool CMainApplication::BInitGL();//可能会改成BInitVulkan
	bool BInitCompositor();


	void CMainApplication::SetupCameras();
	Matrix4 CMainApplication::GetHMDMatrixPoseEye(vr::Hmd_Eye nEye);
	Matrix4 CMainApplication::GetHMDMatrixProjectionEye(vr::Hmd_Eye nEye);
	Matrix4 CMainApplication::GetCurrentViewProjectionMatrix(vr::Hmd_Eye nEye);
	void CMainApplication::UpdateHMDMatrixPose();
	Matrix4 CMainApplication::ConvertSteamVRMatrixToMatrix4(const vr::HmdMatrix34_t &matPose);

	bool CMainApplication::SetupStereoRenderTargets();

public:
	vr::IVRSystem *m_pHMD;
	vr::TrackedDevicePose_t m_rTrackedDevicePose[vr::k_unMaxTrackedDeviceCount];

	float m_fNearClip;
	float m_fFarClip;

	uint32_t m_nRenderWidth;
	uint32_t m_nRenderHeight;

	Matrix4 m_mat4HMDPose;
	Matrix4 m_mat4eyePosLeft;
	Matrix4 m_mat4eyePosRight;

	Matrix4 m_mat4ProjectionCenter;
	Matrix4 m_mat4ProjectionLeft;
	Matrix4 m_mat4ProjectionRight;

	Matrix4 m_rmat4DevicePose[vr::k_unMaxTrackedDeviceCount];
};