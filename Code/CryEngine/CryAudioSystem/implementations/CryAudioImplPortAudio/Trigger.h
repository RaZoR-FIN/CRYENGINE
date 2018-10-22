// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <ATLEntityData.h>
#include <PoolObject.h>
#include <portaudio.h>

namespace CryAudio
{
namespace Impl
{
namespace PortAudio
{
enum class EEventType : EnumFlagsType
{
	None,
	Start,
	Stop,
};

class CTrigger final : public ITrigger, public CPoolObject<CTrigger, stl::PSyncNone>
{
public:

	CTrigger() = delete;
	CTrigger(CTrigger const&) = delete;
	CTrigger(CTrigger&&) = delete;
	CTrigger& operator=(CTrigger const&) = delete;
	CTrigger& operator=(CTrigger&&) = delete;

	explicit CTrigger(
		uint32 const pathId_,
		int const numLoops_,
		double const sampleRate_,
		EEventType const eventType_,
		CryFixedStringT<MaxFilePathLength> const& filePath_,
		PaStreamParameters const& streamParameters_,
		CryFixedStringT<MaxFilePathLength> const& folder,
		CryFixedStringT<MaxFilePathLength> const& name,
		bool const isLocalized);

	virtual ~CTrigger() override = default;

	// CryAudio::Impl::ITrigger
	virtual ERequestStatus Load() const override                             { return ERequestStatus::Success; }
	virtual ERequestStatus Unload() const override                           { return ERequestStatus::Success; }
	virtual ERequestStatus LoadAsync(IEvent* const pIEvent) const override   { return ERequestStatus::Success; }
	virtual ERequestStatus UnloadAsync(IEvent* const pIEvent) const override { return ERequestStatus::Success; }
	// ~CryAudio::Impl::ITrigger

	uint32 const                                pathId;
	int const                                   numLoops;
	double                                      sampleRate;
	EEventType const                            eventType;
	CryFixedStringT<MaxFilePathLength>          filePath;
	PaStreamParameters                          streamParameters;
	CryFixedStringT<MaxFilePathLength> const    m_folder;
	CryFixedStringT<MaxControlNameLength> const m_name;
	bool const                                  m_isLocalized;
};
} // namespace PortAudio
} // namespace Impl
} // namespace CryAudio