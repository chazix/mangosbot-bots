#include "botpch.h"
#include "../../playerbot.h"
#include "QuestRewardActions.h"

using namespace ai;

bool QuestRewardAction::Execute(Event& event)
{
    Player* requester = event.getOwner() ? event.getOwner() : GetMaster();
    if (event.getParam() == "auto") {
        ai->SetQuestRewardOptionType(QuestRewardOptionType::QUEST_REWARD_OPTION_AUTO);
    }
    else if (event.getParam() == "list") {
        ai->SetQuestRewardOptionType(QuestRewardOptionType::QUEST_REWARD_OPTION_LIST);
    }
    else if (event.getParam() == "ask") {
        ai->SetQuestRewardOptionType(QuestRewardOptionType::QUEST_REWARD_OPTION_ASK);
    }
    else if (event.getParam() == "reset") {
        ai->SetQuestRewardOptionType(QuestRewardOptionType::QUEST_REWARD_CONFIG_DRIVEN);
    }
    else if (event.getParam() == "?") {
        auto currentQuestRewardOption = ai->GetQuestRewardOptionType();
        ostringstream out;
        out << "Current: |cff00ff00";
        switch (currentQuestRewardOption) {
        case QuestRewardOptionType::QUEST_REWARD_OPTION_AUTO:
            out << "Auto";
            break;
        case QuestRewardOptionType::QUEST_REWARD_OPTION_LIST:
            out << "List";
            break;
        case QuestRewardOptionType::QUEST_REWARD_OPTION_ASK:
            out << "Ask";
            break;
        default:
            out << "Config Driven";
            break;
        }
        ai->TellPlayer(requester, out);
    }
    else {
        ai->TellPlayer(requester, "Usage: quest reward [auto|list|ask|reset|?]");
    }

    return true;
}