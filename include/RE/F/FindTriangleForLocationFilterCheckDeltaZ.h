#pragma once

namespace RE
{
	class FindTriangleForLocationFilter
	{
	public:
		inline static constexpr auto RTTI = RTTI_FindTriangleForLocationFilter;
		inline static constexpr auto VTABLE = VTABLE_FindTriangleForLocationFilter;
		
		virtual ~FindTriangleForLocationFilter();  // 00

		// add
		virtual bool IsValidTri(NiPoint3* a_location, BSNavmesh* a_navMesh, std::uint16_t a_tri, NiPoint3* a_pointOnTri) = 0;
	};
	static_assert(sizeof(FindTriangleForLocationFilter) == 0x8);

	class FindTriangleForLocationFilterCheckDeltaZ : public FindTriangleForLocationFilter
	{
	public:
		inline static constexpr auto RTTI = RTTI_FindTriangleForLocationFilterCheckDeltaZ;
		inline static constexpr auto VTABLE = VTABLE_FindTriangleForLocationFilterCheckDeltaZ;
		
		FindTriangleForLocationFilterCheckDeltaZ() :
			maxDistAbove(std::numeric_limits<float>::max()),
			maxDistBelow(std::numeric_limits<float>::max())
		{
			stl::emplace_vtable(this);
		}
		
		~FindTriangleForLocationFilterCheckDeltaZ() override = default;  // 00

		// add
		bool IsValidTri(NiPoint3* a_location, BSNavmesh* a_navMesh, std::uint16_t a_tri, NiPoint3* a_pointOnTri) override;

		// members
		float maxDistAbove;  // 08
		float maxDistBelow;  // 0C
	};
	static_assert(sizeof(FindTriangleForLocationFilterCheckDeltaZ) == 0x10);
}
