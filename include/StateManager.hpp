//
//  StateManager.hpp
//  shmup_sfml
//
//  Created by Alexis Rodriguez on 2/18/22.
//  Copyright © 2022 Alexis Rodriguez. All rights reserved.
//

#ifndef StateManager_hpp
#define StateManager_hpp

#include <stack>
#include <memory>
#include "State.hpp"

namespace Engine{
    class StateManager{
        private:
            std::stack<std::unique_ptr<Engine::State>> m_stateStack;
            std::unique_ptr<Engine::State> m_newSate;
            bool m_add;
            bool m_replace;
            bool m_remove;
        public:
            StateManager();
            ~StateManager();
            void add(std::unique_ptr<Engine::State> toAdd, bool replace = false);
            void popCurrent();
            void processStateChange();
            std::unique_ptr<Engine::State>& getCurrentState();
    };
}

#endif /* StateManager_hpp */
