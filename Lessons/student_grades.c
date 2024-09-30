#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_GRADES 10

int main(void) {
	// array declaration and initialization
	const int scores[NUM_STUDENTS][NUM_GRADES] = {
	{85, 90, 92, 88, 95, 87, 91, 83, 89, 94},
        {78, 82, 80, 85, 90, 88, 84, 79, 81, 86},
        {92, 89, 95, 91, 93, 87, 90, 92, 88, 96},
        {75, 78, 82, 80, 85, 81, 79, 77, 83, 84},
        {88, 91, 87, 93, 90, 92, 85, 89, 94, 90}
	};

	// before bounds checking
	int sum = 0;
	for (int student_idx = 0; student_idx < NUM_STUDENTS; student_idx++) {
		for (int grade_idx = 0; grade_idx <= NUM_GRADES; grade_idx++) { // incorrect bounds checking
		sum += scores[student_idx][grade_idx];
		}
	}
	printf("Sum (before bounds checking): %d\n", sum);

	// after bounds checking
	sum = 0;
	for (int student_idx = 0; student_idx < NUM_STUDENTS; student_idx++) {
		for (int grade_idx = 0; grade_idx < NUM_GRADES; grade_idx++) {
		sum += scores[student_idx][grade_idx];
		}
	}
	printf("Sum (after bounds checking): %d\n", sum);

	// calculating average scores
	for (int student_idx = 0; student_idx < NUM_STUDENTS; student_idx++) {
		int student_sum = 0;
		for (int grade_idx = 0; grade_idx < NUM_GRADES; grade_idx++) {
			student_sum += scores[student_idx][grade_idx];
		}
		double average = (double)student_sum / NUM_GRADES;
		printf("Student %d - Average score: %.2f\n", student_idx + 1, average);
	}

	// Finding the student with the highest final exam grade
	int max_exam_grade = scores[0][NUM_GRADES - 1];
	int max_student_index = 0;
	for (int student_idx = 1; student_idx < NUM_STUDENTS; student_idx++) {
		if (scores[student_idx][NUM_GRADES - 1] > max_exam_grade) {
			max_exam_grade = scores[student_idx][NUM_GRADES - 1];
			max_student_index = student_idx;
		}
	}
	printf("Student %d had the highest final exam grade: %d\n", max_student_index + 1, max_exam_grade);

	return 0;
}
