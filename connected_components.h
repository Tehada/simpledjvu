#pragma once

#include <vector>
#include <string>

#include "types.h"

const int MIN_LEVEL = 10;
const int MAX_LEVEL = 250;
const int LEVEL_STEP = 15;
const int LEVELS = (MAX_LEVEL - MIN_LEVEL) / LEVEL_STEP + 1;

const int MIN_WIDTH = 4;
const int MIN_HEIGHT = 4;

using std::vector;

struct ConnectedComponent {
    int left;
    int right;
    int top;
    int bottom;
    int color;
    bitonal_image form;
    vector<int> childs;
    void save(FILE *file) const;
    ConnectedComponent();
    int width() const;
    int height() const;
};

struct ConnectedComponentForest {
    const vector<vector<ConnectedComponent *> > components;
    ConnectedComponentForest(const vector<vector<ConnectedComponent *> > &components): components(components) {
    }
    void save(std::string path) const;
    void save_component(std::string path, int level, int number) const;
    double component_quality(const ConnectedComponent &component) const;
    vector<ConnectedComponent *> get_best_subset();
    class ConnectedComponentForestForwardIterator {
        private:
            const ConnectedComponentForest &forest;
            int level, number;
        public:
            const ConnectedComponent& operator *();
            ConnectedComponentForestForwardIterator& operator ++();
            bool operator !=(const ConnectedComponentForestForwardIterator &other) const;
            ConnectedComponentForestForwardIterator(int level, int number, const ConnectedComponentForest &forest);
    };
    ConnectedComponentForestForwardIterator begin() const;
    ConnectedComponentForestForwardIterator end() const;
};

ConnectedComponentForest build_connected_components_forest(byte *pixels, int width, int height);

void place_components(const vector<ConnectedComponent *> components, bitonal_image &image);