//#include <stdio.h>
//#define MAX_JUDGES 3
//#define MAX_STRING 25
//#define MAX_CONTESTANTS 10
//#define WINNER_CUTOFF  6.5
//
//struct Score
//{
//	double judgeScore[MAX_JUDGES];
//};
//
//struct Contestant
//{
//	char name[MAX_STRING];
//	struct Score score;
//	double average;
//};
//
//struct Competition
//{
//	char compName[MAX_STRING];
//	struct Contestant contestants[MAX_CONTESTANTS];
//	int numContestants;
//};
//
//double avg(const struct Contestant* c)
//{
//	return (c->score.judgeScore[0] + c->score.judgeScore[1] + c->score.judgeScore[2]) / 3.0;
//}
//
//int main(void)
//{
//	struct Contestant winners[MAX_CONTESTANTS] = { {{ 0 }} };
//	struct Competition national =
//	{
//		"National",
//		{
//			{"Tyrion Lannister", { {3.5, 5.5, 4} }},
//			{"Jon Snow", { {7.5, 5.5, 6.5} }},
//			{"Arya Stark", { {8, 8.5, 9} }},
//		},
//		3
//	};
//	int i, j, k, numWinners = 0;
//	
//	for (i = 0; i < national.numContestants; i++)
//	{
//		national.contestants[i].average = avg(&national.contestants[i]);
//		if (national.contestants[i].average >= WINNER_CUTOFF)
//		{
//			for (j = 0; j < numWinners && winners[j].average < national.contestants[i].average; j++)
//			{
//				 // no code to see here
//			}
//			for (k = numWinners; k > j; k--)
//			{
//				winners[k] = winners[k - 1];
//			}
//
//			winners[j] = national.contestants[i];
//			numWinners++;
//			}
//		}
//	printf("Winners of the %s competition\n", national.compName);
//	for (i = 0; i < numWinners; i++)
//	{
//		printf("%20s%4.1lf\n", winners[i].name, winners[i].average);
//	}
//	
//	return 0;
//}
//
