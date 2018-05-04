package com.thoughtworks.app.command;

/**
 * Base implementation of Command. It abstracts away the string line containing each command
 */
public abstract class AbstractCommand implements Command {

    private final String commandLine;

    public AbstractCommand(final String commandLine) {
        this.commandLine = commandLine;
    }

    public final String getCommandLine() {
        return commandLine;
    }

}
