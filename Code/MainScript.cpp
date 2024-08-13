#include "MainScript.hpp"
#include "ScriptCallback.hpp"
#include "Lists.hpp"
#include "Natives.hpp"
#include "Timer.hpp"
#include "Translation.hpp"
#include "CustomText.hpp"
#include "UI/UIManager.hpp"
#include "UI/BoolOption.hpp"
#include "UI/ChooseOption.hpp"
#include "UI/NumberOption.hpp"
#include "UI/RegularOption.hpp"
#include "UI/SubOption.hpp"
#include "UI/RegularSubmenu.hpp"
#include "UI/PlayerSubmenu.hpp"
#include "Functions.hpp"

// This base is skid-friendly. It's for skids who can't get off Mod Hub :) So, I took Mod Hub's function loop, like functions.cpp and .h.
// basicly nice way of saying learn how to code......
// also added mod hubs ytd loader but u can fix it :)
// HIDEING FROM MOD HUB LOVERS.
// SO PLZ STOP USIENG MOD HUB AND USE CUSTOM BIGER BASER.

///<CREDITS>
//ATOMIX
//NOW GIVE ME HEAD FOR MY WORK :)
///</CREDITS>

namespace Big
{
	enum Submenu : std::uint32_t
	{
		SubmenuHome,
		SubmenuSettings,
		SubmenuSettingsHeader,
		SubmenuSettingsHeaderStaticBackground,
		SubmenuSettingsHeaderGradientBackground,
		SubmenuSettingsHeaderText,
		SubmenuSettingsSubmenuBar,
		SubmenuSettingsOption,
		SubmenuSettingsFooter,
		SubmenuSettingsDescription,
		SubmenuSettingsInput,
		SubmenuSettingsLanguage,
		SubmenuSelectedPlayer,
		SubmenuPlayerList,
		SubmenuTest,
	    Demorecovery,
	};

	bool MainScript::IsInitialized()
	{
		return m_Initialized;
	}

	ScriptType MainScript::GetType()
	{
		return ScriptType::Game;
	}

	void MainScript::Initialize()
	{
		m_Initialized = true;
		using namespace UserInterface;

		g_CustomText->AddText(CONSTEXPR_JOAAT("HUD_JOINING"), "Isn't " BIGBASE_NAME "HIDEING FROM MOD HUB LOVERS");
		g_CustomText->AddText(CONSTEXPR_JOAAT("HUD_TRANSP"), "Isn't " BIGBASE_NAME "HIDEING FROM MOD HUB LOVERS");

		g_UiManager->AddSubmenu<RegularSubmenu>("Home", SubmenuHome, [](RegularSubmenu* sub)
		{
			sub->AddOption<BoolOption<bool>>("Godmode", nullptr, &Godmode, BoolDisplay::OnOff);
			sub->AddOption<RegularOption>("Max Health", " max health.", [] { ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 400); });
			sub->AddOption<RegularOption>("Max Armour", "max armour.", []
			{
				PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 200);
			});
			sub->AddOption<SubOption>(BIG_TRANSLATE("Demo_detected_recovery"), nullptr, Demorecovery);
			sub->AddOption<SubOption>(BIG_TRANSLATE("Demo_sub"), nullptr, SubmenuTest);
			sub->AddOption<SubOption>("Players", nullptr, SubmenuPlayerList);
			sub->AddOption<SubOption>("Settings", nullptr, SubmenuSettings);
			sub->AddOption<RegularOption>(std::move(RegularOption("Version").SetRightText(g_GameVariables->m_GameBuild)));
			sub->AddOption<BoolOption<bool>>("Log Script Events", nullptr, &g_LogScriptEvents, BoolDisplay::OnOff);
			sub->AddOption<RegularOption>("Unload", "Unload the menu.", []
			{
				g_Running = false;
			});
		});

		g_UiManager->AddSubmenu<RegularSubmenu>(BIG_TRANSLATE("Demo_sub"), Demorecovery, [](RegularSubmenu* sub)
			{
				//heres sum detected recovery :)
				//fix ur self to lazy got better things to work on aka axelrod mod menu :)
				//sub->AddOption<RegularOption>("Max Crate Price", nullptr, [] { globalHandle(277988).As<int>() = 3000000; });
				///sub->AddOption<RegularOption>("Reset Sell Cooldown", nullptr, [] { globalHandle(277754).As<int>() = 1; });
				//sub->AddOption<RegularOption>("Reset Buy Cooldown", nullptr, [] { globalHandle(277753).As<int>() = 1; });
				sub->AddOption<RegularOption>(("MaxStats"), nullptr, []
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STAM"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STRN"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_LUNG"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_DRIV"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_FLY"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_SHO"), 100, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STL"), 100, 0);
					});
				sub->AddOption<RegularOption>("Fast Run", nullptr, []
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CHAR_ABILITY_1_UNLCK"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CHAR_ABILITY_2_UNLCK"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CHAR_ABILITY_3_UNLCK"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CHAR_FM_ABILITY_1_UNLCK"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CHAR_FM_ABILITY_2_UNLCK"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CHAR_FM_ABILITY_3_UNLCK"), -1, true);
					});
				sub->AddOption<RegularOption>("Alien Tatto", nullptr, []
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_TATTOO_FM_CURRENT_32"), 2147483647, true);
					});

				sub->AddOption<RegularOption>("Free Paragon", nullptr, [] {
					STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("CAS_VEHICLE_REWARD"), true, true);
					});

				sub->AddOption<RegularOption>("Prize Ride", nullptr, [] {
					STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_CARMEET_PV_CHLLGE_CMPLT"), true, true);
					});
				sub->AddOption<RegularOption>(("2bill story mode money"), "W.", [] {
					Hash stat0 = $("SP0_TOTAL_CASH");
					Hash stat1 = $("SP1_TOTAL_CASH");
					Hash stat2 = $("SP2_TOTAL_CASH");
					STATS::STAT_SET_INT(stat0, INT_MAX, 1);
					STATS::STAT_SET_INT(stat1, INT_MAX, 1);
					STATS::STAT_SET_INT(stat2, INT_MAX, 1);
					});
				sub->AddOption<RegularOption>("Max Job Money", "After you spawned this sell it", []
					{
						int NETWORK_HANDLE[76];
						NETWORK::NETWORK_HANDLE_FROM_PLAYER(PLAYER::PLAYER_PED_ID(), &NETWORK_HANDLE[0], 13);
						const char* rockstarID = rockstarID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);
						//NETWORKCASH::NETWORK_INITIALIZE_CASH(100000, 0); (0x3DA5ECD1A56CBA6D);
						//NETWORKCASH::NETWORK_RECEIVE_PLAYER_JOBSHARE_CASH, 100000, rockstarID;
						//NETWORKCASH::NETWORK_CAN_SPEND_MONEY;
					});
				sub->AddOption<RegularOption>("Reset Vehicle Sell Limit", "If you sold too many cars.", []
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_VEHICLE_SELL_TIME"), 0, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_NUM_CARS_SOLD_TODAY"), 0, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_VEHICLE_SELL_TIME"), 0, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_NUM_CARS_SOLD_TODAY"), 0, 0);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MONEY_EARN_SELLING_VEH"), 50000, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MONEY_EARN_SELLING_VEH"), 50000, true);
					});
				sub->AddOption<RegularOption>("Change car price to 1M", "After you spawned this sell it", []
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MONEY_EARN_SELLING_VEH"), 1000000, false);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MONEY_EARN_SELLING_VEH"), 1000000, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MONEY_EARN_SELLING_VEH"), 1000000, true);
					});
			});

		g_UiManager->AddSubmenu<RegularSubmenu>(BIG_TRANSLATE("Demo_sub"), SubmenuTest, [](RegularSubmenu* sub)
		{
			sub->AddOption<RegularOption>(BIG_TRANSLATE("RegularOption_demo"), "A regular option.", []
			{
				g_Logger->Info("You pressed the test option");
			});

			static bool testBool1{};
			sub->AddOption<BoolOption<bool>>(BIG_TRANSLATE("God Mode"), nullptr, &Godmode, BoolDisplay::OnOff);
			static bool testBool2{};
			sub->AddOption<BoolOption<bool>>(BIG_TRANSLATE("BoolYesNo_demo"), nullptr, &testBool2, BoolDisplay::YesNo);

			static std::int32_t int32Test{ 69 };
			sub->AddOption<NumberOption<std::int32_t>>("Int32", nullptr, &int32Test, 0, 100);

			static std::int64_t int64Test{ 420 };
			sub->AddOption<NumberOption<std::int64_t>>("Int64", nullptr, &int64Test, 0, 1000, 10);

			static float floatTest{ 6.9f };
			sub->AddOption<NumberOption<float>>("Float", nullptr, &floatTest, 0.f, 10.f, 0.1f, 1);

			static std::vector<std::uint64_t> vector{ 1, 2, 3 };
			static std::size_t vectorPos{};

			sub->AddOption<ChooseOption<const char*, std::size_t>>("Array", nullptr, &Lists::DemoList, &Lists::DemoListPos);
			sub->AddOption<ChooseOption<std::uint64_t, std::size_t>>("Vector", nullptr, &vector, &vectorPos);
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Settings", SubmenuSettings, [](RegularSubmenu* sub)
		{
			sub->AddOption<SubOption>("Header", nullptr, SubmenuSettingsHeader);
			sub->AddOption<SubOption>("Infobar", nullptr, SubmenuSettingsSubmenuBar);
			sub->AddOption<SubOption>("Options", nullptr, SubmenuSettingsOption);
			sub->AddOption<SubOption>("Footer", nullptr, SubmenuSettingsFooter);
			sub->AddOption<SubOption>("Description", nullptr, SubmenuSettingsDescription);
			sub->AddOption<SubOption>("Input", nullptr, SubmenuSettingsInput);
			sub->AddOption<SubOption>("Language", nullptr, SubmenuSettingsLanguage);
			sub->AddOption<NumberOption<float>>("X Position", nullptr, &g_UiManager->m_PosX, 0.f, 1.f, 0.01f, 2);
			sub->AddOption<NumberOption<float>>("Y Position", nullptr, &g_UiManager->m_PosY, 0.f, 1.f, 0.01f, 2);
			sub->AddOption<NumberOption<float>>("Width", nullptr, &g_UiManager->m_Width, 0.01f, 1.f, 0.01f, 2);
			sub->AddOption<BoolOption<bool>>("Sounds", nullptr, &g_UiManager->m_Sounds, BoolDisplay::OnOff);
			sub->AddOption<BoolOption<std::atomic_bool>>("Log Window", nullptr, &g_Settings.m_LogWindow, BoolDisplay::OnOff);
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Language", SubmenuSettingsLanguage, [](RegularSubmenu* sub)
		{
			namespace fs = std::filesystem;
			fs::directory_iterator dirIt{ g_TranslationManager->GetTranslationDirectory() };
			for (auto&& dirEntry : dirIt)
			{
				if (dirEntry.is_regular_file())
				{
					auto path = dirEntry.path();
					if (path.has_filename())
					{
						sub->AddOption<RegularOption>(path.stem().u8string().c_str(), nullptr, [=]
						{
							g_TranslationManager->LoadTranslations(path.stem().u8string().c_str());
						});
					}
				}
			}

		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Infobar", SubmenuSettingsSubmenuBar, [](RegularSubmenu* sub)
		{
			sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_SubmenuBarHeight, 0.01f, 0.1f, 0.001f, 3);
			sub->AddOption<NumberOption<float>>("Text Size", nullptr, &g_UiManager->m_SubmenuBarTextSize, 0.01f, 1.f, 0.01f, 2);

			sub->AddOption<NumberOption<std::uint8_t>>("Background R", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Background G", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Background B", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Background A", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Text R", nullptr, &g_UiManager->m_SubmenuBarTextColor.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Text G", nullptr, &g_UiManager->m_SubmenuBarTextColor.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Text B", nullptr, &g_UiManager->m_SubmenuBarTextColor.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Text A", nullptr, &g_UiManager->m_SubmenuBarTextColor.a, '\0', static_cast<std::uint8_t>(255));
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Options", SubmenuSettingsOption, [](RegularSubmenu* sub)
		{
			sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_OptionHeight, 0.01f, 0.1f, 0.001f, 3);
			sub->AddOption<NumberOption<float>>("Text Size", nullptr, &g_UiManager->m_OptionTextSize, 0.01f, 1.f, 0.01f, 2);

			sub->AddOption<NumberOption<std::uint8_t>>("Selected Background R", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Selected Background G", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Selected Background B", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Selected Background A", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background R", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background G", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background B", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background A", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));

			sub->AddOption<NumberOption<std::uint8_t>>("Selected Text R", nullptr, &g_UiManager->m_OptionSelectedTextColor.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Selected Text G", nullptr, &g_UiManager->m_OptionSelectedTextColor.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Selected Text B", nullptr, &g_UiManager->m_OptionSelectedTextColor.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Selected Text A", nullptr, &g_UiManager->m_OptionSelectedTextColor.a, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text R", nullptr, &g_UiManager->m_OptionUnselectedTextColor.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text G", nullptr, &g_UiManager->m_OptionUnselectedTextColor.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text B", nullptr, &g_UiManager->m_OptionUnselectedTextColor.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text A", nullptr, &g_UiManager->m_OptionUnselectedTextColor.a, '\0', static_cast<std::uint8_t>(255));
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Footer", SubmenuSettingsFooter, [](RegularSubmenu* sub)
		{
			sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_FooterHeight, 0.01f, 0.1f, 0.001f, 3);
			sub->AddOption<NumberOption<float>>("Sprite Size", nullptr, &g_UiManager->m_FooterSpriteSize, 0.01f, 1.f, 0.001f, 3);

			sub->AddOption<NumberOption<std::uint8_t>>("Background R", nullptr, &g_UiManager->m_FooterBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Background G", nullptr, &g_UiManager->m_FooterBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Background B", nullptr, &g_UiManager->m_FooterBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Background A", nullptr, &g_UiManager->m_FooterBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Sprite R", nullptr, &g_UiManager->m_FooterSpriteColor.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Sprite G", nullptr, &g_UiManager->m_FooterSpriteColor.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Sprite B", nullptr, &g_UiManager->m_FooterSpriteColor.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("Sprite A", nullptr, &g_UiManager->m_FooterSpriteColor.a, '\0', static_cast<std::uint8_t>(255));
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Header", SubmenuSettingsHeader, [](RegularSubmenu* sub)
		{
			sub->AddOption<ChooseOption<const char*, std::size_t>>("Type", nullptr, &Lists::HeaderTypesFrontend, &Lists::HeaderTypesPosition, true, []
			{
				g_UiManager->m_HeaderType = Lists::HeaderTypesBackend[Lists::HeaderTypesPosition];
			});

			switch (g_UiManager->m_HeaderType)
			{
			case HeaderType::Static:
				sub->AddOption<SubOption>("Background", nullptr, SubmenuSettingsHeaderStaticBackground);
				break;
			case HeaderType::Gradient:
				sub->AddOption<SubOption>("Gradient", nullptr, SubmenuSettingsHeaderGradientBackground);
				break;
			}

			sub->AddOption<SubOption>("Text", nullptr, SubmenuSettingsHeaderText);
			sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_HeaderHeight, 0.01f, 0.2f, 0.001f, 3);
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Header Background", SubmenuSettingsHeaderStaticBackground, [](RegularSubmenu* sub)
		{
			sub->AddOption<NumberOption<std::uint8_t>>("R", nullptr, &g_UiManager->m_HeaderBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("G", nullptr, &g_UiManager->m_HeaderBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("B", nullptr, &g_UiManager->m_HeaderBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("A", nullptr, &g_UiManager->m_HeaderBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Header Gradient", SubmenuSettingsHeaderGradientBackground, [](RegularSubmenu* sub)
		{
			sub->AddOption<BoolOption<bool>>("Transparent", nullptr, &g_UiManager->m_HeaderGradientTransparent, BoolDisplay::YesNo);
			sub->AddOption<BoolOption<bool>>("Flip", nullptr, &g_UiManager->m_HeaderGradientFlip, BoolDisplay::YesNo);

			sub->AddOption<NumberOption<std::uint8_t>>("R1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("G1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("B1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("A1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.a, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("R2", nullptr, &g_UiManager->m_HeaderGradientColorRight.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("G2", nullptr, &g_UiManager->m_HeaderGradientColorRight.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("B2", nullptr, &g_UiManager->m_HeaderGradientColorRight.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("A2", nullptr, &g_UiManager->m_HeaderGradientColorRight.a, '\0', static_cast<std::uint8_t>(255));
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Header Text", SubmenuSettingsHeaderText, [](RegularSubmenu* sub)
		{
			sub->AddOption<BoolOption<bool>>("Enable", nullptr, &g_UiManager->m_HeaderText, BoolDisplay::OnOff);
			sub->AddOption<NumberOption<float>>("Size", nullptr, &g_UiManager->m_HeaderTextSize, 0.1f, 2.f, 0.01f, 2);
			sub->AddOption<NumberOption<std::uint8_t>>("R", nullptr, &g_UiManager->m_HeaderTextColor.r, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("G", nullptr, &g_UiManager->m_HeaderTextColor.g, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("B", nullptr, &g_UiManager->m_HeaderTextColor.b, '\0', static_cast<std::uint8_t>(255));
			sub->AddOption<NumberOption<std::uint8_t>>("A", nullptr, &g_UiManager->m_HeaderTextColor.a, '\0', static_cast<std::uint8_t>(255));
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Description", SubmenuSettingsDescription, [](RegularSubmenu* sub)
		{
			sub->AddOption<NumberOption<float>>("Padding", "Padding before the description rect.", &g_UiManager->m_DescriptionHeightPadding, 0.01f, 1.f, 0.001f,
 3);
			sub->AddOption<NumberOption<float>>("Height", "Size of the description rect.", &g_UiManager->m_DescriptionHeight, 0.01f, 1.f, 0.001f, 3);
			sub->AddOption<NumberOption<float>>("Text Size", "Size of the description text.", &g_UiManager->m_DescriptionTextSize, 0.1f, 2.f, 0.01f, 2);
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Input", SubmenuSettingsInput, [](RegularSubmenu* sub)
		{
			sub->AddOption<NumberOption<std::int32_t>>("Open Delay", nullptr, &g_UiManager->m_OpenDelay, 10, 1000, 10, 0);
			sub->AddOption<NumberOption<std::int32_t>>("Back Delay", nullptr, &g_UiManager->m_BackDelay, 10, 1000, 10, 0);
			sub->AddOption<NumberOption<std::int32_t>>("Enter Delay", nullptr, &g_UiManager->m_EnterDelay, 10, 1000, 10, 0);
			sub->AddOption<NumberOption<std::int32_t>>("Vertical Delay", nullptr, &g_UiManager->m_VerticalDelay, 10, 1000, 10, 0);
			sub->AddOption<NumberOption<std::int32_t>>("Horizontal Delay", nullptr, &g_UiManager->m_HorizontalDelay, 10, 1000, 10, 0);
		});

		g_UiManager->AddSubmenu<RegularSubmenu>("Players", SubmenuPlayerList, [](RegularSubmenu* sub)
		{
			for (std::uint32_t i = 0; i < 32; ++i)
			{
				if (auto ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))
				{
					sub->AddOption<SubOption>(PLAYER::GET_PLAYER_NAME(i), nullptr, SubmenuSelectedPlayer, [=]
					{
						g_SelectedPlayer = i;
					});
				}
			}
		});

		g_UiManager->AddSubmenu<PlayerSubmenu>(&g_SelectedPlayer, SubmenuSelectedPlayer, [](PlayerSubmenu* sub)
		{
			sub;
		});
	}

	void MainScript::Destroy()
	{
		g_UiManager.reset();
	}

	void MainScript::Tick()
	{
		FunctionsOnTick();
		g_UiManager->OnTick();
	}
}
