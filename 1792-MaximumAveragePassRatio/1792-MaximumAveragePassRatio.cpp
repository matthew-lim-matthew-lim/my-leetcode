class Solution {
public:
    struct FloatingPointCompare {
        bool operator()(const double& lhs,
                        const double& rhs) const
        {
            // Define a small epsilon for the comparison
            // tolerance
            const double epsilon = 1e-9;
            // Adjust epsilon based on the precision
            // requirements
            return lhs + epsilon < rhs;
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Assign it greedily with a priority queue. Seems legit.
        priority_queue<vector<double>> pq;

        // Each pq entry is the gains gotten from choosing to increment that class. 

        for (vector<int>& cls : classes) {
            double pass_diff = (static_cast<double>(cls[0] + 1) / (cls[1] + 1)) - (static_cast<double>(cls[0]) / cls[1]);
            pq.push({pass_diff, static_cast<double>(cls[0]), static_cast<double>(cls[1])});
        }

        // Iterate through extra students
        for (int i = 0; i < extraStudents; i++) {
            vector<double> max_diff = pq.top();
            pq.pop();
            int stu_pass = max_diff[1];
            int stu_total = max_diff[2];

            double pass_diff_val = ((max_diff[1] + 2) / 
                (max_diff[2] + 2)) - ((max_diff[1] + 1) / (max_diff[2] + 1));

            vector<double> pass_diff = { pass_diff_val, max_diff[1] + 1, max_diff[2] + 1 };

            pq.push(pass_diff);
        }

        // Calculate average pass ratio
        double total_pass = 0;
        while (!pq.empty()) {
            vector<double> max_diff = pq.top();
            pq.pop();
            total_pass += max_diff[1] / max_diff[2];
        }

        return total_pass / classes.size();
    }
};