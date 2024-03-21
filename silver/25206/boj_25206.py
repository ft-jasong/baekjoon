total_lecture_point = 0
grade_sum = 0
grade_map = {}
grade_map['A+'] = 4.5
grade_map['B+'] = 3.5
grade_map['C+'] = 2.5
grade_map['D+'] = 1.5
grade_map['A0'] = 4.0
grade_map['B0'] = 3.0
grade_map['C0'] = 2.0
grade_map['D0'] = 1.0
grade_map['F'] = 0.0
for _ in range(20):
    name, lecture_point, grade = input().split()
    if grade != 'P':
        total_lecture_point += float(lecture_point)
        grade_sum += grade_map[grade] * float(lecture_point)
print(grade_sum / total_lecture_point)